# NF表示域的个数，$NF表示最后一个域，NR表示number
# name age
# alice 21
# ryan 30

# name alice ryan
# age 21 30

awk '
{
	rows = NF
	for (i = 1; i <= NF; i++) {
		if (NR == 1) {
			s[i] = $i
		} else {
			s[i] = s[i] " " $i
		}
	}

}
END {
	for (i = 1; i <= rows; i++) {
		printf "%s\n", s[i]
	}
}
' file.txt