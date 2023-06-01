chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {
    const tab = tabs[0];
    chrome.tabs.sendMessage(tab.id, { action: "openYouTube", trackTitle: "Track Title" });
  });
  