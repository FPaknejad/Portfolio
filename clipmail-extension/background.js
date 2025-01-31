chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {
  if (request.action === 'generateAIResponse') {
    const { text, notes } = request;
    generateAIResponse(text, notes).then((reply) => {
      sendResponse({ reply });
    }).catch((error) => {
      sendResponse({ error: error.message });
    });
    return true; // Required for async response
  }
});

async function generateAIResponse(text, notes) {
  const apiKey = await getAPIKey();
  if (!apiKey) {
    throw new Error('OpenAI API key is missing. Please set it in the settings.');
  }

  // Detect language of the extracted text
  const language = detectLanguage(text);

  // Generate prompt for OpenAI
  const prompt = `Extracted Text: ${text}\nUser Instructions: ${notes}\nGenerate a well-formatted email reply in ${language}:`;

  const response = await fetch('https://api.openai.com/v1/completions', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${apiKey}`,
    },
    body: JSON.stringify({
      model: 'text-davinci-003',
      prompt,
      max_tokens: 150,
    }),
  });

  const data = await response.json();
  return data.choices[0].text.trim();
}

// Simple language detection (you can use a library like "franc" for better accuracy)
function detectLanguage(text) {
  const langCode = franc(text);
  const languageName = new Intl.DisplayNames(['en'], { type: 'language' }).of(langCode);
  return languageName || 'English';
}

async function getAPIKey() {
  return new Promise((resolve) => {
    chrome.storage.sync.get(['apiKey'], (result) => {
      resolve(result.apiKey);
    });
  });
}