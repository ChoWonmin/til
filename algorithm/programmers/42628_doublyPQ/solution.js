function solution(operations) {
  let pq = [];

  operations.forEach(e => {
    if (e[0] === 'I') {
      pq.push(e.split(' ')[1] * 1);
    } else if (e[0] === 'D' && pq.lenth !== 0) {
      const val = e.split(' ')[1] * 1;

      if (val > 0) {
        pq = pq.sort();
        pq.pop();
      } else if (val < 0) {
        pq = pq.sort((a, b) => b - a);
        pq.pop();
      }
    }
  });

  return pq.length === 0 ? [0, 0] : [Math.max(...pq), Math.min(...pq)];
}
