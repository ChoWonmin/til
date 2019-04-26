function solution(s) {
  var answer = '';

  if (s.length % 2 == 1) {
    answer = s[parseInt(s.length / 2)];
  } else {
    let ind = parseInt(s.length / 2);
    answer = s[ind - 1] + s[ind];
  }

  return answer;
}
