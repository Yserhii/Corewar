.name			"bot_and"		#comment
.comment		"komment"		#comment
								#comment
								#comment
	ld %170, r1					#comment
	ld %95, r2					#comment
	and r1, r2, r3
	st r3, 100
	and %65535, %61999, r4
	st r4, 100
	and -14, -10, r5
	st r5, 100
	and -28, %4294967295, r6
	st r6, 100
