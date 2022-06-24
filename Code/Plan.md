___
# Les balises indispensables pour un GUI simple

## Les balises
1. <u>Doivent commencer par une majuscule</u>
2. <u>Camel case (ex: UneNouvelleBalise)</u>
3. <u>doit être documentée </u>

```xml
<!-- rendering context -->
<Window></Window>
<Canvas></Canvas>

<!-- GUI tools -->
<Menu></Menu>
<Button></Button>
<TextField></TextField>
<TextInput></TextInput>
```
<br>

___
# Les champs accessibles dans toutes les balises

## Champs:

- name (string)
- parent (screen, window, canvas, id)
- coordinates (absolute, relative, centred)
- width (integer)
- height (integer)
- x (integer)
- y (integer)

## Possible Values:

## Unitées:
- px (pixels)
- % (pourcentage)

<br>

___
# API et implémentation dans le code
### dependencies.json
```json
{
}
```

### main.cpp
```cpp
int main()
{
}
```

### dependence.html
```xml
<!-- main rendering area covering the full user window and is relative to the center of this window, default parent is the screen  -->
<Window width="100%" height="100%" coordinates="centred">

    <!-- new rendering area relative to the screen, it is independent from the main canvas until the main canvas is closed -->
    <Window width="1080px" height="720px" parent="screen">

        <!-- the default position of the test will be centred in the parent window -->
        <TextField coordinates="centred">This window is external to the main application window<TextField>
    </Window>

    <!-- default parent is the node behind here it is the main canvas -->
    <Window width="20px" height="20px">
    </Window>

    <Script when="beginning" frequency="everytime">
        [&](ApplicationContext& context) -> void
        {
            display.SetText(context.name);
            UserData* data = (UserData*)context.user_data;
            return;
        }
    </Script>

    <Button x="25%">Quit</Button>
</Window>
```
