/*
break
    break如果用于循环, 则是用来终止循环
    break如果用于switch, 则用来终止switch
    break不能直接用于if, 除非if属于循环/switch内部的子语句.
        eg:
        for(i=0; i<3; ++i)
        {
            if(3>2)
                break; //break虽然是if内部的语句, 但break终止的是外部的for循环.
            printf("嘿嘿\n"); //永远不会输出
        }
    在多层循环中, break只能终止最里面包裹它的循环.
        eg:
        for(i=0; i<3; ++i)
        {
            for(j=1; j<4; ++j)
                break; //break只能终止距离它最近的循环.
            printf("首长好\n");
        }
    在多层switch嵌套中, break只能终止距离它最近的switch
        eg:
        int x=1, y=0, a=0, b=0;
        switch(x) //第一个switch
        {
            case 1:
                switch(y) //第二个switch
                {
                    case 0: a++; break;//结束的是第二个switch
                    case 1: b++; break;
                }
                b = 100;
                break;//结束的是第一个switch
            case 2:
                a++;
                b++;
                break;
        }
        printf("%d, %d\n", a, b);
        //结果: 1, 100

continue
    用于跳过本次循环余下的语句.
    转去判断是否需要执行下一次循环.
        eg 1:
        for(1; 2; 3)
        {
            A;
            B;
            continue; //如果执行该语句,则该语句执行完后, 会执行语句3; C, D都会被跳过.
            C;
            D;
        }
        eg 2:
        while(表达式)
        {
            A;
            B;
            continue; //如果执行该语句,则该语句执行完后, 会执行表达式判断; C, D都会被跳过.
            C;
            D;
        }
*/