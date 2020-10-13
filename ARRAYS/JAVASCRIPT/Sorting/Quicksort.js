function QuickSort(arr, left = 0, right = arr.length - 1) {
  let len = arr.length,
      index
  if(len > 1) {
    index = partition(arr, left, right)
    if(left < index - 1) {
      QuickSort(arr, left, index - 1)
    } 
    if(index < right) {
      QuickSort(arr, index, right)
    }
  }
  return arr
}

function partition(arr, left, right) {
  let middle = Math.floor((right + left) / 2),
      pivot = arr[middle],
      i = left,
      j = right
  while(i <= j) {
    while(arr[i] < pivot) {
      i++
    }
    while(arr[j] > pivot) {
      j--
    }
    if(i <= j) {
      [arr[i], arr[j]] = [arr[j], arr[i]]
      i++
      j--
    }
  }
  return i
}

let arr = [10,5,2,7,4,12,8,1];
console.log(QuickSort(arr));
