.name "Grigorii"
.comment "I am Russian robocop"

record:
	sti		r1, %:bege_gen, %1
	sti		r1, %:bege, %1
	sti		r1, %:spaw, %1
	sti		r1, %:side, %1
	sti		r1, %:ii4, %1
	sti		r1, %:ii4, %9
	sti		r1, %:ii4, %17
	sti		r1, %:ii4l, %1
	sti		r1, %:ii4ld, %2
	sti		r1, %:ii2, %1
	ld		%0, r16
	fork	%:spaw


side:
	live	%402343
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
	st		r2, -105
	st		r2, -114
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	st		r2, -510
	zjmp	%:side

bege_gen:
	live	%42323
	fork	%:bege_gen
	ld		%0, r16

bege:
	live	%34402
	zjmp	%:bege

spaw:
	live	%4320423
	zjmp	%3
	fork	%:spaw

side_pr:
	ld		%0, r2
	ld		%0, r16

ii4:
	live	%429034
	fork	%:ii3
	live	%301123
	fork	%:ii2
	live	%490543
	fork	%:ii1
ii4ld:
	ld		%0, r2
	ld		%2883523, r3
	ld		%0, r16
ii4l:
	live	%4930423	
	ld		%0, r16
	zjmp	%:coco

ii2:
	live	%4342342
	fork	%:side_pr
	ld		%2883523, r2
	ld		%3101251, r3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:coco

ii3:
	live	%4239013
	fork	%:ii4
	live	%4093282
	fork	%:bege_gen
	ld		%42942016, r2
	ld		%4332899, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:coco

ii1:
	ld		%576721, r2
	ld		%3182387, r3
	ld		%0, r16
	zjmp	%:coco

coco:
	st		r2, 15
	st		r3, -1
ii_live:
	live	%0
