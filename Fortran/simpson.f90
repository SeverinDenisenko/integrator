! Created by Severin on 23.09.2022.

function simpson(f, a, b, n) result(res)
    implicit none
    real(8) :: f
    real(8) :: a
    real(8) :: b
    real(8) :: res, s1, s2, h, sp
    integer(4) :: n, i

    s1 = 0;
    s2 = 0;
    h = (b - a) / n
    do i = 3, n - 1, 2
        s2 = s2 + f(h * i)
    enddo
    do i = 2, n, 2
        s1 = s1 + f(h * i)
    enddo
    sp = f(a) + f(b) + 4 * s1 + 2 * s2
    res = (h/3) * sp

end function simpson
