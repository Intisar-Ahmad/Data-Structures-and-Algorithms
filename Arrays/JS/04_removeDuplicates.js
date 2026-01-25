// this is another leetcode easy

let arrays = [
    [1,1,2],
    [0,0,1,1,1,2,2,3,3,4]
]


function remove(arr) {
    if(arr.length == 0) return 0;
    let i = 1;
    let j = 1;

    while(j < arr.length && i < arr.length){
        if(arr[j] == arr[j-1]){
            j++;
        }
        else{
            arr[i++] = arr[j++];
        }
    }

    return i;
    
}


for (let i = 0; i < arrays.length; i++) {
    console.log(remove(arrays[i]));
}