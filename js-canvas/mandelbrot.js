var mandelbrot = (function(){

    var resolutionDevider = 1;
    var exportObj = {};
    var imageWidth, imageHeight, maxIteration, canvasContext, center, zoom;
    var colors = [], xPixelMap = [], yPixelMap = [];
    var startTime;

    exportObj.draw = function(canvas, iteration, imageZoom, imageCenter){
        updateFields(canvas, iteration, imageZoom, imageCenter);
        generateColorsMap();
        generatePixelMap();
        for(var x = 0; x < imageWidth; x++){
            for(var y = 0; y < imageHeight; y++){
                var escapeTime = calculateEscapeTime(xPixelMap[x], yPixelMap[y]);   
                drawPixel(x, y, colors[escapeTime]); 
            }
        }
    }

    function updateFields(canvas, iteration, imageZoom, imageCenter){
        maxIteration = iteration;
        imageWidth = canvas.width / resolutionDevider;
        imageHeight = canvas.height / resolutionDevider;
        if(imageCenter){
            center = imageCenter; zoom = imageZoom;   
        }else{
            center = {'x': -0.75, 'y':0}; zoom = 1;    
        }     
        canvasContext = canvas.getContext("2d");
    }

    function generatePixelMap(){
        xPixelMap = []; yPixelMap = [];
        for(var x = 0; x < imageWidth; x++){
            xPixelMap[x] = scaleX(x);    
        }   
        for(var y = 0; y < imageHeight; y++){
            yPixelMap[y] = scaleY(y); 
        } 
    }

    function drawPixel(x,y,colorString){
        canvasContext.fillStyle = colorString;
        canvasContext.fillRect(x*resolutionDevider, y*resolutionDevider, resolutionDevider, resolutionDevider);
    }

    function calculateEscapeTime(cx, cy){
        var x = 0, y = 0;
        for(var i = 0; i < maxIteration && x*x + y*y < 4 ;i++){
            _x = x*x - y*y + cx;
            y = 2*x*y + cy
            x = _x;
        }
        return i;
    }

    function zeroPaddedHex(int){
        var hex = "";
        if(int < 16){
            hex ="0"
        }
        hex += int.toString(16);
        return hex;
    }

    function rgbToColorString(r, g, b){
        return "#"+zeroPaddedHex(r)+zeroPaddedHex(g)+zeroPaddedHex(b);
    }

    function generateColorsMap(){
        // Forget about HSL, RGB switch for "real" spectrum colors :)
        for(var i = 0; i < (maxIteration+1); i++){
            c = Math.round((i / maxIteration) * 1024);
            var r,b,g;
            if(c < 256){
                r = 255; g = c; b = 0;
            }else if(c < 512){
                r = 512 - c; g = 255; b = 0;
            }else if(c < 768){
                r = 0; g = 768 - c; b = c - 512;
            }else if(c < 1024){
               r = c - 768; g = 0; b = 255; 
            }
            else{
                r = g = b = 0;
            }

            colors.push(rgbToColorString(r,g,b));   
        } 
    }

    function scaleX(x){
        var delta = 3.5 / zoom;
        return ((x / imageWidth) * delta) + (center.x - (delta/2));
    }

    function scaleY(y){
        delta = 2 / zoom;
        return ((y / imageHeight) * delta) + (center.y - (delta/2));
    } 

    return exportObj;
}());
