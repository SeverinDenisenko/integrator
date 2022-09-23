! Created by Severin on 23.09.2022.

function log_f(value, base) result(res)
    implicit none
    real(8) :: value
    real(8) :: base
    real(8) :: res
    res = log(value) / log(base)
end function log_f