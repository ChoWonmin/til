function solution(arr) {
  var answer = [];

  let tmp = arr[0];
  for (var i = 1; i < arr.length; i++) {
    if (arr[i] !== tmp) answer.push(tmp);
    tmp = arr[i];
  }

  answer.push(tmp);

  return answer;
}
