async function onloadStatus() {
    try {
        await getWifiSSIDData();
        await getWifiQualityData();
    } catch (error) {
        console.error('Error:', error);
    }
}

setInterval(async function () {
    try {
        await getWifiSSIDData();
        await getWifiQualityData();
    } catch (error) {
        console.error('Error:', error);
    }
}, 3500);

// WiFi SSID Data
async function getWifiSSIDData() {
    try {
        const response = await fetch('/readWifiSSID');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("wifiSSID").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

// WiFi Quality Data
async function getWifiQualityData() {
    try {
        const response = await fetch('/readWifiQuality');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("wifiQuality").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}