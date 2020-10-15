function solution(numbers) {    
    const hash = {};
    
    for (let i=0; i<numbers.length; i++) {
        for (let j=0; j<numbers.length; j++) {
            if (i!==j) {
                let a = numbers[i];
                let b = numbers[j];
                
                hash[a+b] = 0;
            }
        }    
    }
    
    return Object.keys(hash).map(ele => ele * 1).sort((a,b) => a<b);
}