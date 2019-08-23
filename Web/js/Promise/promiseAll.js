async function main() {

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
  console.log(endTime - startTime, res ); // 204 [ 3, 'bar', 'foo' ]
}

main();