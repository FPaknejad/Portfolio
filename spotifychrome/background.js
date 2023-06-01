chrome.action.onClicked.addListener(async () => {
  const [tab] = await chrome.tabs.query({ active: true, currentWindow: true });
  if (tab.url.startsWith('https://open.spotify.com/collection/tracks')) {
    chrome.tabs.sendMessage(tab.id, { action: "openYouTube" });
  }
});
