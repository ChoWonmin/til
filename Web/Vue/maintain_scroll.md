# maintain to position vue component scroll

```js
data() {
  return {
    scollTop: 0
  }
}
methods: {
  scrollUpdateEvent() {
    this.scollTop = this.$refs.target.scolltop;
  }
}
update() {
  // scroll이 rendering된 이후의 life cycle에 접근하는 것은 update()를 통해서 가능하다
  this.$refs.target.scolltop = this.scrollTop;
}
```

## error

## Reference
