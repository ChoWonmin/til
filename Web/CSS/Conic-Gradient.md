# Conic Gradient

> A conic gradient is similar to a radial gradient. Both are circular and use the center of the element as the source point for color stops. However, where the color stops of a radial gradient emerge from the center of the circle, a conic gradient places them around the circle.

## 1. Simple Pie-Chart

``` html
<div class="pie"></div>
```

``` css
.pie {
  /* Basic layout */
  display: inline-block;
  width: 3.75em;
  height: 3.75em;
  border-radius: 50%;

  /* A little styling */
  border: .15em solid #fff;
  box-shadow: 0 .075em .2em .05em rgba(0,0,0,.25);

  /* fixes a minor clipping issue in Chrome */
  background-origin: border-box;

  background-image: conic-gradient(
    #d44 72deg,      /* 20%             20  * 3.6 =  72 degrees      (end of segment 1) */
    #fc3 72deg,      /* 45%       (45 + 20) * 3.6 = 234 degrees    (start of segment 2) */
    #fc3 234deg,     /* 45%       (45 + 20) * 3.6 = 234 degrees      (end of segment 2) */
    #ac0 0           /* 35%     last stop is always 360 degrees    (start of segment 3) */
  );
}
```

## 2. Using Variable

``` html
<div class="pie" style="--segment1: 40; --segment2: 70;"></div>
<div class="pie" style="--segment1: 20; --segment2: 50;"></div>
<div class="pie" style="--segment1: 10; --segment2: 80;"></div>
```

``` css
.pie {
  background-image: conic-gradient(
    #d44 calc(3.6deg * var(--segment1)),
    #fc3 0 calc(3.6deg * var(--segment2)),
    #ac0 0
  );
}
```
