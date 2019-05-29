.name		".comment 'privet'"
.comment	"reufeigfuewgfu"

live:
	live %1
loop:
	live %:live
	sti r1, %:live, %1
	and r6, r6, r6
	sti r1, %:live, %200
	fork %8
