function solution(n, m) {
  const answer = [];
  let gcd, lcm;
  let big, small;

  big = n >= m ? n : m;
  small = n >= m ? m : n;

  lcm = big * small;

  while (small != 0) {
    let mod = big % small;
    big = small;
    small = mod;
  }

  gcd = big;
  lcm /= gcd;

  answer.push(gcd, lcm);
  return answer;
}
