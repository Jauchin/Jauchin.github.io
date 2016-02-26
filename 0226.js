var digit = [0, 0, 0, 0];
var leftAry = new Array();
var i;
var inputDigit1, inputDigit2, inputDigit3, inputDigit4;
var tmp, tmp1, tmp2, tmp3, tmp4;
var numberA, numberB;
var answer;

function start() {
    tmp = document.getElementById("display1");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display2");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display3");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display4");
    tmp.innerHTML = "-";
    for (i = 0; i < 10000; i++) {
        digit[0] = parseInt(i / 1000);
        digit[1] = parseInt(i / 100) % 10;
        digit[2] = parseInt(i / 10) % 10;
        digit[3] = i % 10;
        if (!((digit[0] == digit[1]) || (digit[0] == digit[2]) || (digit[0] == digit[3]) || (digit[1] == digit[2]) || (digit[1] == digit[3]) || (digit[2] == digit[3]))) {
            leftAry.push(i);
        }
    }

    answer = leftAry[Math.floor(Math.random() * leftAry.length)];
    answer = parseInt(answer);
    alert(answer);
}

function input() {
    var t = document.createElement("p");
    t.innerHTML = tmp1.innerHTML + tmp2.innerHTML + tmp3.innerHTML + tmp4.innerHTML;
    var s = document.getElementById("addInput");
    s.appendChild(t);

    inputDigit1 = document.getElementById("display1");
    inputDigit2 = document.getElementById("display2");
    inputDigit3 = document.getElementById("display3");
    inputDigit4 = document.getElementById("display4");

    var guessInput = inputDigit1.innerHTML + inputDigit2.innerHTML + inputDigit3.innerHTML + inputDigit4.innerHTML;


    guessInput = parseInt(guessInput);

    /*

    var isRepeat=true;

    while (isRepeat) {
        init();
        guessInput = parseInt(guessInput);
        if (leftAry.indexOf(guessInput) !== -1) {
            isRepeat = false;
        }
    }

    */
    numberA = checkA(guessInput, answer);
    numberB = checkB(guessInput, answer);

    t = document.createElement("p");
    t.innerHTML = numberA + "A" + numberB + "B";
    s = document.getElementById("addResult");
    s.appendChild(t);


    // alert(numberA);
}

function zero() {
    tmp = document.getElementById("display1");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display2");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display3");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display4");
    tmp.innerHTML = "-";
}


function inputTemp(tmp) {
    tmp1 = document.getElementById("display1");
    tmp2 = document.getElementById("display2");
    tmp3 = document.getElementById("display3");
    tmp4 = document.getElementById("display4");
    if (tmp1.innerHTML == "-") {
        tmp1.innerHTML = tmp;
        return 0;
    }
    if (tmp2.innerHTML == "-") {
        tmp2.innerHTML = tmp;
        return 0;
    }
    if (tmp3.innerHTML == "-") {
        tmp3.innerHTML = tmp;
        return 0;
    }
    if (tmp4.innerHTML == "-") {
        tmp4.innerHTML = tmp;
        return 0;
    }

}


function init() {
    tmp = document.getElementById("display1");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display2");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display3");
    tmp.innerHTML = "-";
    tmp = document.getElementById("display4");
    tmp.innerHTML = "-";

}
window.onload = init;



var guessCount = 0;
while (guessInput !== answer) {
    guessCount++
    alert("This is " + guessCount + "th guess! Your guessInput is " + guessInput);
    guessInput = answer;
}


function removeArray(guessInput, leftAry) {

    for (var i = 0; i < leftAry.length; i++) {
        if ((checkA(guessInput, answer) !== (checkA(leftAry[i], answer))) && (checkB(guessInput, answer) !== (checkB(leftAry[i], answer)))) {
            leftAry.pop(leftAry[i]);
        }
    }
}


var m, n;

function checkA(m, n) {
    var temp = [0, 0, 0, 0];
    temp[0] = digit[0] = parseInt(m / 1000);
    temp[1] = digit[1] = parseInt(m / 100) % 10;
    temp[2] = digit[2] = parseInt(m / 10) % 10;
    temp[3] = digit[3] = m % 10;

    digit[0] = parseInt(n / 1000);
    digit[1] = parseInt(n / 100) % 10;
    digit[2] = parseInt(n / 10) % 10;
    digit[3] = n % 10;

    var counter = 0;
    if (temp[0] == digit[0])
        counter++;
    if (temp[1] == digit[1])
        counter++;
    if (temp[2] == digit[2])
        counter++;
    if (temp[3] == digit[3])
        counter++;
    return counter;
}

function checkB(m, n) {
    var temp = [0, 0, 0, 0];
    temp[0] = digit[0] = parseInt(m / 1000);
    temp[1] = digit[1] = parseInt(m / 100) % 10;
    temp[2] = digit[2] = parseInt(m / 10) % 10;
    temp[3] = digit[3] = m % 10;

    digit[0] = parseInt(n / 1000);
    digit[1] = parseInt(n / 100) % 10;
    digit[2] = parseInt(n / 10) % 10;
    digit[3] = n % 10;

    var counter = 0;
    if (temp[0] == digit[1])
        counter++;
    if (temp[0] == digit[2])
        counter++;
    if (temp[0] == digit[3])
        counter++;
    if (temp[1] == digit[0])
        counter++;
    if (temp[1] == digit[2])
        counter++;
    if (temp[1] == digit[3])
        counter++;
    if (temp[2] == digit[0])
        counter++;
    if (temp[2] == digit[1])
        counter++;
    if (temp[2] == digit[3])
        counter++;
    if (temp[3] == digit[0])
        counter++;
    if (temp[3] == digit[1])
        counter++;
    if (temp[3] == digit[2])
        counter++;
    return counter;
}
