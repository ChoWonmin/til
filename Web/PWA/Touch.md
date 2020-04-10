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

```js
// Handle the start of gestures
this.handleGestureStart = function (evt) {
  evt.preventDefault();

  if (evt.touches && evt.touches.length > 1) {
    return;
  }

  // Add the move and end listeners
  if (window.PointerEvent) {
    evt.target.setPointerCapture(evt.pointerId);
  } else {
    // Add Mouse Listeners
    document.addEventListener("mousemove", this.handleGestureMove, true);
    document.addEventListener("mouseup", this.handleGestureEnd, true);
  }

  initialTouchPos = getGesturePointFromEvent(evt);

  swipeFrontElement.style.transition = "initial";
}.bind(this);

// Handle end gestures
this.handleGestureEnd = function (evt) {
  evt.preventDefault();

  if (evt.touches && evt.touches.length > 0) {
    return;
  }

  rafPending = false;

  // Remove Event Listeners
  if (window.PointerEvent) {
    evt.target.releasePointerCapture(evt.pointerId);
  } else {
    // Remove Mouse Listeners
    document.removeEventListener("mousemove", this.handleGestureMove, true);
    document.removeEventListener("mouseup", this.handleGestureEnd, true);
  }

  updateSwipeRestPosition();

  initialTouchPos = null;
}.bind(this);
```

### TouchEvent Event

|                |                                                                      |
| -------------- | -------------------------------------------------------------------- |
| touches        | 화면의 모든 현재 터치 목록(터치가 어떤 DOM 요소에 있는지는 상관없음) |
| targetTouches  | 이벤트가 바인딩된 DOM 요소에 있는 현재 터치 목록                     |
| changedTouches | 변경될 경우 이벤트를 발생시키는 터치 목록                            |

```js
function getGesturePointFromEvent(evt) {
  var point = {};

  if (evt.targetTouches) {
    // Prefer Touch Events
    point.x = evt.targetTouches[0].clientX;
    point.y = evt.targetTouches[0].clientY;
  } else {
    // Either Mouse event or Pointer Event
    point.x = evt.clientX;
    point.y = evt.clientY;
  }

  return point;
}
```

### requestAnimationFrame

```js
// Handle the start of gestures
this.handleGestureStart = function (evt) {
  evt.preventDefault();

  if (evt.touches && evt.touches.length > 1) {
    return;
  }

  // Add the move and end listeners
  if (window.PointerEvent) {
    evt.target.setPointerCapture(evt.pointerId);
  } else {
    // Add Mouse Listeners
    document.addEventListener("mousemove", this.handleGestureMove, true);
    document.addEventListener("mouseup", this.handleGestureEnd, true);
  }

  initialTouchPos = getGesturePointFromEvent(evt);

  swipeFrontElement.style.transition = "initial";
}.bind(this);

this.handleGestureMove = function (evt) {
  evt.preventDefault();

  if (!initialTouchPos) {
    return;
  }

  lastTouchPos = getGesturePointFromEvent(evt);

  if (rafPending) {
    return;
  }

  rafPending = true;

  window.requestAnimFrame(onAnimFrame);
}.bind(this);

function onAnimFrame() {
  if (!rafPending) {
    return;
  }

  var differenceInX = initialTouchPos.x - lastTouchPos.x;

  var newXTransform = currentXPosition - differenceInX + "px";
  var transformStyle = "translateX(" + newXTransform + ")";
  swipeFrontElement.style.webkitTransform = transformStyle;
  swipeFrontElement.style.MozTransform = transformStyle;
  swipeFrontElement.style.msTransform = transformStyle;
  swipeFrontElement.style.transform = transformStyle;

  rafPending = false;
}
```

### NPM Package

vue2-touch-events
https://www.npmjs.com/package/vue2-touch-events

---

### Reference

https://developers.google.com/web/fundamentals/design-and-ux/input/touch

https://www.npmjs.com/package/vue2-touch-events

https://alligator.io/vuejs/vue-touch-events/
