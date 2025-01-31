document.addEventListener('DOMContentLoaded', () => {
    const extractedText = document.getElementById('extracted-text');
    const userNotes = document.getElementById('user-notes');
    const generateResponseButton = document.getElementById('generate-response');
    const aiResponse = document.getElementById('ai-response');
    const copyResponseButton = document.getElementById('copy-response');
    const insertEmailButton = document.getElementById('insert-email');
  
    // Load Tesseract.js
    const { createWorker } = Tesseract;
  
    // Read image from clipboard and extract text
    generateResponseButton.addEventListener('click', async () => {
      try {
        // Read image from clipboard
        const clipboardItems = await navigator.clipboard.read();
        for (const item of clipboardItems) {
          for (const type of item.types) {
            if (type.startsWith('image/')) {
              const blob = await item.getType(type);
              const imageUrl = URL.createObjectURL(blob);
  
              // Initialize Tesseract worker
              const worker = await createWorker('eng'); // Default to English
              const { data: { text } } = await worker.recognize(imageUrl);
              await worker.terminate();
  
              // Display extracted text
              extractedText.value = text;
  
              // Generate AI response
              const notes = userNotes.value;
              if (!text) {
                alert('No text extracted from the screenshot.');
                return;
              }
  
              chrome.runtime.sendMessage(
                { action: 'generateAIResponse', text, notes },
                (response) => {
                  if (response.error) {
                    aiResponse.value = `Error: ${response.error}`;
                  } else {
                    aiResponse.value = response.reply;
                  }
                }
              );
            }
          }
        }
      } catch (error) {
        console.error('Error processing clipboard image:', error);
        extractedText.value = 'Failed to extract text. Please try again.';
      }
    });
  
    // Copy AI response to clipboard
    copyResponseButton.addEventListener('click', () => {
      navigator.clipboard.writeText(aiResponse.value).then(() => {
        alert('Response copied to clipboard!');
      });
    });
  
    // Insert AI response into email (placeholder for now)
    insertEmailButton.addEventListener('click', () => {
      alert('Insert into email functionality is not implemented yet.');
    });
  });