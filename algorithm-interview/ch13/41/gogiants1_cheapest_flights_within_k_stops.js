/**
 * @param {number} n
 * @param {number[][]} flights
 * @param {number} src
 * @param {number} dst
 * @param {number} k
 * @return {number}
 */
 var findCheapestPrice = function(n, flights, src, dst, k) {
    //flights[i] => 출발지, 도착지, 가격
   // 최대 k번 환승
   // 최소 비용(최단 경로 알고리즘)
   // minheap 이용 한다고 생각.
   const adjList = new Map(); // 각 키마다 인접 vertex list로 저장 입력 순서 기억. 키, 값
   
   for(let [u, v, w] of flights){ // u: start vertex, v: end vertex, w: cost
       if(adjList.has(u)) adjList.get(u).push([v, w]);
       else adjList.set(u,[ [v, w] ]);
   }
   
   const queue = [[0, src, k + 1]]; //[cost, srcCity, stops + 1] why k + 1? k+1번 환승 부터는 조건 만족 X 의미 없음.
   const visited = new Map();
   
   while(queue.length){
       queue.sort((a, b) => a[0]- b[0]); // cost 값의 크기대로 정렬
       const [cost, city, stops] = queue.shift(); // 가격의 오름차순으로 정렬되어 있는 queue에서 pop(0)한 것과 같은 효과
       visited.set(city, stops); // 가장 저렴하게 방문 할 수 있는 도시 방문.
       
       if (city === dst) return cost; // 우리가 원하는 것.
       if (stops <= 0 || !adjList.has(city)) continue;   
       for(let [nextCity, nextCost] of adjList.get(city)){
           if (visited.has(nextCity) && visited.get(nextCity) >= stops -1) continue; 
           queue.push([cost+nextCost, nextCity, stops-1]);
       }
   }
   return -1;
};