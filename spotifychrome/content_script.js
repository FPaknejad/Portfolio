function openYouTubeVideo(trackTitle) {
    const youtubeSearchUrl = `https://www.youtube.com/results?search_query=${encodeURIComponent(trackTitle)}`;
    window.open(youtubeSearchUrl, "_blank");
  }
  
  chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.action === "openYouTube") {
      const trackTitleElement = document.querySelector(".tracklist-name-link");
      const trackTitle = trackTitleElement.textContent.trim();
      openYouTubeVideo(trackTitle);
    }
  });
  