.name		"zjmp"
.comment	"zzzzzzzzz"

# ld %255, r2
# st r2, 500
and %1, %2, r1
zjmp %5
live %1
and %1, %3, r2
zjmp %30
and %1, %3, r2
st r2, 100
zjmp %3
