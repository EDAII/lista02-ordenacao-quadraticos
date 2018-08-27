def gap_insertion_sort(array, start, gap):
	for i in range(start + gap, len(array), gap):
		current_value = array[i]
		position = i
		while position >= gap and array[position - gap] > current_value:
			array[position] = array[position - gap]
			position = position - gap
		array[position] = current_value
