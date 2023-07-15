func validUtf8(d []int) bool {
    data := d[:]
    for len(data) > 0 {
        if data[0] & 0x80 == 0 {
            data = data[1:]
        } else if (data[0] & 0xe0) == 0xc0 {
            if len(data) < 2 {
                return false
            }
            if (data[1] & 0xc0) != 0x80 {
                return false
            }
            data = data[2:]
        } else if (data[0] & 0xf0 == 0xe0) {
            if len(data) < 3 {
                return false
            }
            for i := 1; i <= 2; i++ {
                if (data[i] & 0xc0) != 0x80 {
                    return false
                }
            }
            data = data[3:]
        } else if (data[0] & 0xf8 == 0xf0) {
            if len(data) < 4 {
                return false
            }
            for i := 1; i <= 3; i++ {
                if (data[i] & 0xc0) != 0x80 {
                    return false
                }
            }
            data = data[4:]
        } else {
            return false
        }
    }
    return true
}
