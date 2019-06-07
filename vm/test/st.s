.name		"ST_operation"
.comment	"t_reg , t_reg-t_ind"


ld	%100, r1
ld	%50, r16
st  r1, 50
st  r16, 100
ld	%-1000, r2
st  r2, 150
ld	%-2000, r3
st  r3, 150
# ld	%100, r1
# st  r1, r2
# st  r2, 50
# st  r2, 10
# st  r2, -60
# st  r2, -10
