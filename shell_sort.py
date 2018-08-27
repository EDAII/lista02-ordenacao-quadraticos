def shell_sort (array):
	sublistcount = len(array) // 2
	while sublistcount > 0:
		for startposition in range(sublistcount):
			gapInsertionSort(array, startposition, sublistcount)
		print("After increments of size", sublistcount, "The list is", array)
		sublistcount = sublistcount//2
