import webbrowser

webbrowser.register(
    name="brave", 
    klass="None", 
    instance=webbrowser.Chrome(r"C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe"), 
    preferred=True
    )

problem = 2**38
webbrowser.open(url=f"pythonchallenge.com/pc/def/{problem}.html", new=0)

