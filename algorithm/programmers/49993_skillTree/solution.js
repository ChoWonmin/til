function solution(skill, skill_trees) {
  var answer = 0;

  skill_trees.forEach(tree => {
    let queue = skill.split('');

    for (const ele of tree) {
      if (queue[0] === ele) {
        queue.shift();
      } else if (queue.find(r => ele === r)) {
        answer--;
        break;
      }
    }
    answer++;
  });

  return answer;
}
