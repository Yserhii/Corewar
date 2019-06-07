.name		"zjmp"
.comment	"zzzzzzzzz"

ld %255, r2
st r2, 530
and %1, %2, r1
zjmp %500
st r2, 1
and %1, %3, r2
st r2, 100
zjmp %3
and %1, %3, r2
st r2, 100
zjmp %3
