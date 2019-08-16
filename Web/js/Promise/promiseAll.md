# Promise.All()

> returns a single Promise that resolves when all of the promises passed as an iterable have resolved or when the iterable contains no promises. It rejects with the reason of the first promise that rejects.

---
## example

### 1. basic

``` js
const promise1 = Promise.resolve(3);
const promise2 = 42;
const promise3 = new Promise(function(resolve, reject) {
  setTimeout(resolve, 100, 'foo');
});

Promise.all([promise1, promise2, promise3]).then(function(values) {
  console.log(values);
}); // Array [3, 42, "foo"]
```

### 2. reject

``` js
const promise1 = Promise.resolve(3);
const promise2 = Promise.reject(42);
const promise3 = new Promise(function(resolve, reject) {
  setTimeout(resolve, 100, 'foo');
});

Promise.all([promise1, promise2, promise3]).then(function(values) {
  console.log(values);
}).then(function (err) {
  coonsole.log(err);
}); // 42
```

### 3. async-await

``` js
async() => {
  const promise1 = Promise.resolve(3);
  const promise2 = Promise.reject(42);
  const promise3 = new Promise(function(resolve, reject) {
    setTimeout(resolve, 100, 'foo');
  });

  const res = await Promise.all([promise1, promise2, promise3]);
  console.log(res); // [3, 42, "foo"]
}

```

### 4. await

``` js
const startTime = new Date();

const promise1 = Promise.resolve(3);
const promise2 = new Promise(function(resolve, reject) {
  setTimeout(resolve, 200, 'bar');
});;
const promise3 = new Promise(function(resolve, reject) {
  setTimeout(resolve, 200, 'foo');
});

const res = await Promise.all([promise1, promise2, promise3]);

const endTime = new Date();
console.log(res); // [3, 42, "foo"]
```
