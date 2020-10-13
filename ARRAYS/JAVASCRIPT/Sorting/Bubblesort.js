function bubbleSort(arr) {

  let swapped=false;

  arr.forEach((item,index) => {

    if (item>arr[index+1]) {
      [arr[index],arr[index+1]] = [arr[index+1],arr[index]];
      swapped=true;
    }
  });
  if (swapped) {
    return bubbleSort(arr);
  }
  return arr;
}

let arr = [10,5,2,7,4,12,8,1];
console.log(bubbleSort(arr));
