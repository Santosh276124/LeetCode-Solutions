/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        
        let ans = x;
        
        for(let i = functions.length-1; i >= 0; i--){
            
           const currfun = functions[i];
            
            ans = currfun(ans);
            
        }
        return ans;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */