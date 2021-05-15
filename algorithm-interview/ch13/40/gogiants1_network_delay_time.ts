/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
 function networkDelayTime(times: number[][], n: number, k: number): number {
    // times[i] = (u_i, v_i, w_i)
    // n개의 노드
    // k는 시작점
    const timeTable = new Array(n + 1).fill(Infinity); // init single node
    
    timeTable[0] = 0;
    timeTable[k] = 0;
    
    let f = true;
    
    while (f){
        f = false;
        times.forEach(([u,v,w]) => { // u는 출발지 v는 도착지 w는 weight
            if(timeTable[u] !== Infinity && timeTable[v] > timeTable[u] + w){
                // relaxation
                timeTable[v] = timeTable[u] + w;
                f = true;
            }
        });
    }
    const res = Math.max(...timeTable);
    
    return res === Infinity ? -1 : res;
    
};