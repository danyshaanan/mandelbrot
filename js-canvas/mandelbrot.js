var mandelbrot = (function(){

    var exportObj = {};
    var imageWidth, imageHeight, maxIteration, canvasContext, center, zoom;
    var colors = [], xPixelMap = [], yPixelMap = [];
    var startTime;

    exportObj.draw = function(canvas, iteration, imageZoom, imageCenter){
        startTime = new Date();
        updateFields(canvas, iteration, imageZoom, imageCenter);
        generateColorsMap();
        generatePixelMap();
        var pixelArray = [];
        for(var x = 0; x < imageWidth; x++){
            pixelArray[x] = [];
            for(var y = 0; y < imageHeight; y++){
                pixelArray[x][y] = colors[calculateEscapeTime(xPixelMap[x],yPixelMap[y])];
            }
        }
        reportTimeInterval('Calculation time');
        renderImage(pixelArray);
        reportTimeInterval('Render time');
    }

    function updateFields(canvas, iteration, imageZoom, imageCenter){
        maxIteration = iteration;
        imageWidth = canvas.width;
        imageHeight = canvas.height;
        if(imageCenter){
            center = imageCenter; zoom = imageZoom;   
        }else{
            center = {'x': -0.75, 'y':0}; zoom = 1;    
        }     
        canvasContext = canvas.getContext("2d");
    }

    function renderImage(imagePixelArray){
        var imageData = canvasContext.getImageData(0, 0, imageWidth, imageHeight);
        var data = imageData.data;

        for(var x = 0; x < imageWidth; x++){
            for(var y = 0; y < imageHeight; y++){
                var rgb = imagePixelArray[x][y];
                var index = (y * imageWidth + x) * 4;
                data[index] = rgb[0];
                data[++index] = rgb[1];
                data[++index] = rgb[2];
                data[++index] = 255;
            }
        } 

        canvasContext.putImageData(imageData, 0, 0);
    }

    function reportTimeInterval(label){
        var now = new Date();
        var time = (now.getTime() - startTime.getTime()) / 1000;
        console.log(label + ": " + time + " seconds");
        startTime = new Date();
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

    function calculateEscapeTime(cx, cy){
        var x = 0, y = 0;
        for(var i = 0; i < maxIteration && x*x + y*y < 4 ;i++){
            _x = x*x - y*y + cx;
            y = 2*x*y + cy
            x = _x;
        }
        return i;
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

            colors.push([r,g,b]);   
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
