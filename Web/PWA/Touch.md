# Touch

## PointerEvents

- Chrome(버전 55 이상), Internet Explorer 및 Edge
- Other Browser : TouchEvents / MouseEvents
- 여러 유형의 입력(예: 마우스, 터치, 펜 이벤트)을 하나의 콜백 세트에 병합

```js
// Check if pointer events are supported.
if (window.PointerEvent) {
  // Add Pointer Event Listener
  swipeFrontElement.addEventListener(
    "pointerdown",
    this.handleGestureStart,
    true
  );
  swipeFrontElement.addEventListener(
    "pointermove",
    this.handleGestureMove,
    true
  );
  swipeFrontElement.addEventListener("pointerup", this.handleGestureEnd, true);
  swipeFrontElement.addEventListener(
    "pointercancel",
    this.handleGestureEnd,
    true
  );
} else {
  // Add Touch Listener
  swipeFrontElement.addEventListener(
    "touchstart",
    this.handleGestureStart,
    true
  );
  swipeFrontElement.addEventListener("touchmove", this.handleGestureMove, true);
  swipeFrontElement.addEventListener("touchend", this.handleGestureEnd, true);
  swipeFrontElement.addEventListener(
    "touchcancel",
    this.handleGestureEnd,
    true
  );

  // Add Mouse Listener
  swipeFrontElement.addEventListener(
    "mousedown",
    this.handleGestureStart,
    true
  );
}
```

---

### Reference

https://developers.google.com/web/fundamentals/design-and-ux/input/touch
