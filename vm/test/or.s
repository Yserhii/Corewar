.name			"or_operation"		#comment
.comment		"komment"		#comment
								#comment
ld %4294901760, r1					#comment
ld %65535, r2					#comment
or r1, r2, r3
st r3, 100
or %65280, %65535, r4
st r4, 100
or -14, -10, r5
st r5, 100
or -24, %255, r6
st r6, 100
