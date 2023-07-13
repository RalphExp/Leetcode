func mod(i, m int) int{
    if i < 0 {
        return i + m
    }
    return i
}

func canCompleteCircuit(gas []int, cost []int) int {
    length := len(gas)
    i := 0
    left := 0
    right := 0

    diff := gas[left] - cost[left]
    for i < length-1 {
        if diff < 0 {
            left = mod(left-1, length)
            diff += gas[left] - cost[left]
        } else {
            right = mod(right+1, length)
            diff += gas[right] - cost[right]
        }
        i++
    }
    if diff >= 0 {
        return left
    }
    return -1
}
