var keyHandler = (function(){

    var exportObj = {};
    var _updateInterval = 200; 
    var listening = false;
    var intervalId;
    var pressedKeys = {
        'zoomIn': false, 
        'zoomOut': false, 
        'up': false, 
        'down': false, 
        'left': false,
        'right': false
    };

    exportObj.listen = function(updateInterval){
        if(updateInterval) _updateInterval = updateInterval;   
        listenToKeyEvent();
        intervalId = window.setInterval(updateLoop, _updateInterval);
    }

    exportObj.stop = function(){
        stopListeningToKeyEvent();
        window.clearInterval(intervalId);  
    }

    function listenToKeyEvent(){
        document.onkeydown = function(e){
            switch(e.keyCode){
                case 81: // Q
                    pressedKeys.zoomOut = true;
                    break;
                case 87: // W
                    pressedKeys.zoomIn = true;
                    break;
                case 38: // Up Arrow
                    pressedKeys.up = true;
                    break;
                case 40: // Down Arrow
                    pressedKeys.down = true;
                    break;
                case 37: // Left Arrow
                    pressedKeys.left = true;
                    break;
                case 39: // Right Arrow
                    pressedKeys.right = true;
                    break;
            }          
        }

        document.onkeyup = function(e){
            switch(e.keyCode){
                case 81: // Q
                    pressedKeys.zoomOut = false;
                    break;
                case 87: // W
                    pressedKeys.zoomIn = false;
                    break;
                case 38: // Up Arrow
                    pressedKeys.up = false;
                    break;
                case 40: // Down Arrow
                    pressedKeys.down = false;
                    break;
                case 37: // Left Arrow
                    pressedKeys.left = false;
                    break;
                case 39: // Right Arrow
                    pressedKeys.right = false;
                    break;
            }          
        }
    }

    function stopListeningToKeyEvent(){
        document.onkeydown = null;    
    }

    function updateLoop(){
        var renderRequired = false;
        if(pressedKeys.zoomOut){
            mandelbrot.zoomOut();
            renderRequired = true;
        }
        if(pressedKeys.zoomIn){
            mandelbrot.zoomIn();
            renderRequired = true;
        }
        if(pressedKeys.up){
            mandelbrot.moveUp();
            renderRequired = true;
        }
        if(pressedKeys.down){
            mandelbrot.moveDown();
            renderRequired = true;
        }
        if(pressedKeys.left){
            mandelbrot.moveLeft();
            renderRequired = true;
        }
        if(pressedKeys.right){
            mandelbrot.moveRight();
            renderRequired = true;
        }
        if(renderRequired){
            mandelbrot.render();
        }    
    }
    
    return exportObj;
}());
