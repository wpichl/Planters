function init()
{
    window.location.hash = '#first';
    startTime();
}

document.addEventListener('DOMContentLoaded', (event) => {
    const fetchBtn : HTMLElement = <HTMLElement> document.getElementById("fetch");
    fetchBtn.addEventListener("click", (event) => {
        fetch('http://192.168.0.2/sensor')
            .then(response => response.text())
            .then(data => {
                // Do something with your data
                console.log(data);
                const obj = JSON.parse(data);
                console.log(obj.sensor);
                const sensordiv : HTMLOutputElement = <HTMLOutputElement> document.getElementById("sensorvalues");
                sensordiv.innerText = `Water moisture: ${obj.sensor}\n Waterable: ${obj.waterable}`;
            });
    });
});
function startTime() {

    let today = new Date();
    let h = today.getHours();
    let m = today.getMinutes();
    let s = today.getSeconds();
    m = checkTime(m);
    s = checkTime(s);
    document.getElementById('txt').innerHTML =
        h + ":" + m + ":" + s;
    document.getElementById('txt2').innerHTML =
        h + ":" + m + ":" + s;
    document.getElementById('txt3').innerHTML =
        h + ":" + m + ":" + s;
    let t = setTimeout(startTime, 1000);
}
function checkTime(i) {
    if (i < 10) {i = "0" + i};  // add zero in front of numbers < 10
    return i;
}




