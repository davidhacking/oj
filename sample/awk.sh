# $0表示整个行

# 统计c文件总大小
# ls -l  *.cpp *.c *.h | awk '{sum+=$5} END {print sum}'

# 统计各个connection状态的用法
# awk 'NR!=1{a[$6]++;} END {for (i in a) print i ", " a[i];}'

# 统计每个用户的进程的占了多少内存（注：sum的RSS那一列）
# ps aux | awk 'NR!=1{a[$1]+=$6;} END { for(i in a) print i ", " a[i]"KB";}'

# 引用环境变量 ENVIRON
# awk -v val=$x '{print $1, $2, $3, $4+val, $5+ENVIRON["y"]}'

# 9x9表
# seq 9 | sed 'H;g' | awk -v RS='' '{for(i=1;i<=NF;i++)printf("%dx%d=%d%s", i, NR, i*NR, i==NR?"\n":"\t")}'


awk '
BEGIN {

}
NR==1 {
	print  "   " $0
}
# # 过滤语句
# $3>0 && NR!=1 {
# 	# awk是按照一行一行处理的
# 	printf "%2s %s\t\t\t%s\n", NR, $1, $4
# }

#  ~ 表示模式开始。/ /中是模式。这就是一个正则表达式的匹配。!~/SYN/ 表示不取SYN模式
# $6 ~/SYN/ {
# 	printf "%2s %s\t\t\t%s\t%s\t%s\n", FNR, $1, $4, $5, $6
# }

# 为文件加上行号
NR!=1 {
	printf "%02s %s\n", NR, $0
}

# {} 内过滤 if($6 ~ /TIME|ESTABLISHED/) print > "1.txt";

END {

}
' tmp.txt

# cat /etc/passwd | awk '
# BEGIN {
# 	FS=":"
# 	printf "%s\t%s\t%s\t%s\t%s\t%s\t%s\t", "用户名", "口令", "用户标识号", "组标识号", "注释性描述", "主目录", "登录Shell"
# }
# {
# 	printf "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", $1, $2, $3, $4, $5, $6, $7
# }
# ' | less