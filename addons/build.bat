del /Q *.pbo

for /D %%i in (*.*) do (
	makepbo -NUP %%i uo_%%i.pbo
)
