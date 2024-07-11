// GFG -> Smallest range in K lists
/*
    question says that find the smallest range in which all the arrays at leats one elelement persent
    => Don't think directly like how can I find a range which is smallest and at least one of the element of each array is persent in that range bcz when u wnat to find answer directly then u couldn't reach anywhere.

    So just devide the question in sub question
    how to do that?
    => here question says two thing or here two sub questions are persent
    first one -> find the a range which is smallest
    second one -> find a range in which least one element of each array persent
    now u can say that u have two sub question but also think which sub question u should takel or solve first or which sub question is required to solve first.

    How can we find that which sub question is required to solve first?
    =>  check the dependices of the sub question, like is sub question is dependent on another sub question or not if dependent then first solve that sub question on which it is dependent then solve this if not then solve directly this one

    Here u can say that finding a smallest range is dependent on the find a range in which at leats one element of each sub array is persent.
    bcz if u want to find a smalest raneg that range must include one lement form each array

    So first think of how can u find a range in which at least one element of each sorted array is persent
    Then after think how could u minize this range such that it does not voilate your first condition

    now further u can break down the sub question find a range in which at least one element of each sub array is persent how?
    => Think like each sub aarya have only one element then and u have to include all the elemnt in your range to make your desire range

    now how can u make a range in which each array have only one element and your range must include at leats one element from each array
    => suppose u have an array in which all these(one-one element) are persent then how can u make a range which include all the elemnt of the array
    Just simply pick the minium and maxium element of the array

    now how can u make a range in which each array have only one element and your range must include at leats one element from each array
    => solution just pick the minium and maximum element of the persent element 

    now you have a range in which at least one element of each array is persent in that range
    => {mini, maxi}

    Now think how could u minimize this range means u want to minimize your mini - maxi differenece 
    => either u can increase the mini or decrease the maxi
    => can u decrease the maxi 
    ans => No, bcz u choose mini and maxi from the 1st element of every array so if u decrese the maxi i.e. u have to go back that is not possible
    => can u increase the mini
    ans => yes first find from which array you mini belong and just pick the next eleement after the mini and find the new mini and maxi
    thus u have alwasy a range in which at least one element pf each subaarys is persent 

    Now compute the differenece of maxi-mini when store it when it is minium update your range and when u reach the end of any array then stop

    suppose u are updating or increasing your mini but that array have not any further element then just stop your processing
*/



