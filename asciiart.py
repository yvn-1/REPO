#!/usr/bin/env python3
# ascii_simple_gauss_out.py — simple image → ASCII with Gaussian edge pop
# Always writes to ascii_output.txt in the current folder

import argparse
from pathlib import Path
from PIL import Image, ImageFilter

# Character ramp: light → dark
CHARS = " .:-=+*#%@"

def main():
    ap = argparse.ArgumentParser(description="Image to ASCII (Gaussian edge pop + dark threshold)")
    ap.add_argument("image", help="path to image file")
    ap.add_argument("-w", "--width", type=int, default=100, help="output width (chars)")
    ap.add_argument("--threshold", type=float, default=0.2,
                    help="dark cutoff [0–1]; higher = more pure black")
    ap.add_argument("--invert", action="store_true",
                    help="flip back to normal brightness mapping")
    ap.add_argument("--gauss", type=float, default=1.2,
                    help="Gaussian radius for unsharp mask (edge size)")
    ap.add_argument("--sharpen", type=float, default=1.0,
                    help="edge boost amount (0 = off, ~0.5–2.0)")
    ap.add_argument("-o", "--output", type=str, default="ascii_output.txt",
                    help="output text file")
    args = ap.parse_args()

    # Load → grayscale
    img = Image.open(args.image).convert("L")

    # Resize with terminal char aspect
    aspect = 0.55
    w0, h0 = img.size
    new_h = max(1, int(h0 / w0 * args.width * aspect))
    img = img.resize((args.width, new_h), Image.LANCZOS)

    # Edge pop (unsharp mask)
    if args.sharpen > 0 and args.gauss > 0:
        percent = int(max(0, min(500, round(args.sharpen * 100))))
        img = img.filter(ImageFilter.UnsharpMask(
            radius=args.gauss, percent=percent, threshold=0
        ))

    # Map pixels → ASCII
    pixels = list(img.getdata())
    chars = CHARS[::-1] if args.invert else CHARS
    n = len(chars) - 1
    rows = []
    for y in range(new_h):
        start = y * args.width
        row = []
        for x in range(args.width):
            v = pixels[start + x] / 255.0
            if v < args.threshold:
                ch = " "
            else:
                t = (v - args.threshold) / (1 - args.threshold)
                idx = max(0, min(n, int(t * n)))
                ch = chars[idx]
            row.append(ch)
        rows.append("".join(row))

    art = "\n".join(rows)
    Path(args.output).write_text(art, encoding="utf-8")
    print(f"✅ ASCII art written to {args.output}")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        pass
