function solution(n) {
  let answer = 0;
  const sieve = new Array(n + 1);
  const max = Math.sqrt(n + 1);

  for (let i = 2; i <= max; i++) {
    if (sieve[i] !== 1) {
      for (let j = i + i; j <= n; j = j + i) {
        sieve[j] = 1;
      }
    }
  }

  for (let i = 2; i <= n; i++) {
    if (!sieve[i]) answer++;
  }

  return answer;
}
