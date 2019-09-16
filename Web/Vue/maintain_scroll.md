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
  this.$refs.target.scolltop = this.scrollTop;
}

```
