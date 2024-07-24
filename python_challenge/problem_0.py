import webbrowser

webbrowser.register(
    name="brave", 
    klass="None", 
    instance=webbrowser.Chrome(r"C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe"), 
    preferred=True
    )

webbrowser.open(url="pythonchallenge.com/pc/def/1.html", new=0)