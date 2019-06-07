.name		"sub_operation"
.comment	"comment"


ld	%-100, r1
ld	%-2000, r2
sub r1, r2, r3
ld	%-100, r4
ld	%100, r5
sub r4, r5, r6
st	r3, 100
st	r6, 200
