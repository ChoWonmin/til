# Beforeinstallprompt

```js
let deferredPrompt;

window.addEventListener("beforeinstallprompt", (e) => {
  // Prevent the mini-infobar from appearing on mobile
  e.preventDefault();
  // Stash the event so it can be triggered later.
  deferredPrompt = e;
  // Update UI notify the user they can install the PWA
  showInstallPromotion();
});
```

### In-app installation flow

```js
buttonInstall.addEventListener("click", (e) => {
  // Hide the app provided install promotion
  hideMyInstallPromotion();
  // Show the install prompt
  deferredPrompt.prompt();
  // Wait for the user to respond to the prompt
  deferredPrompt.userChoice.then((choiceResult) => {
    if (choiceResult.outcome === "accepted") {
      console.log("User accepted the install prompt");
    } else {
      console.log("User dismissed the install prompt");
    }
  });
});
```

### Detect when the PWA was successfully installed

```js
window.addEventListener("appinstalled", (evt) => {
  console.log("installed");
});
```

### Update UI based on how the PWA was launched

```css
@media all and (display-mode: standalone) {
  body {
    background-color: yellow;
  }
}
```

### Track how the PWA was launched

- matchMedia()
- display-mode
- navigator.standalone (Safari on iOS doesn't support)

```js
window.addEventListener("load", () => {
  if (navigator.standalone) {
    console.log("Launched: Installed (iOS)");
  } else if (matchMedia("(display-mode: standalone)").matches) {
    console.log("Launched: Installed");
  } else {
    console.log("Launched: Browser Tab");
  }
});
```

---

### Reference

https://developer.mozilla.org/en-US/docs/Web/API/BeforeInstallPromptEvent

https://web.dev/customize-install/
