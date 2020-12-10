using System.Diagnostics;
using System;

namespace proyecto_final_cs
{
    class Program
    {
		public class RGB
		{
			public int R = 0;
			public int G = 0;
			public int B = 0;
		}

		static readonly Stopwatch sw = new Stopwatch();

		public static long ColorInversion1(RGB [,] img, int n)
		{
			sw.Start();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					img[i, j].R = 255 - img[i, j].R;
					img[i, j].G = 255 - img[i, j].G;
					img[i, j].B = 255 - img[i, j].B;
				}
			}
			sw.Stop();
			return (long)(sw.Elapsed.TotalMilliseconds * 1000000);
		}

		public static long ColorInversion2(RGB[,] img, int n)
		{
			sw.Start();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					img[i, j].R = 255 - img[i, j].R;
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					img[i, j].G = 255 - img[i, j].G;
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					img[i, j].B = 255 - img[i, j].B;
				}
			}
			sw.Stop();
			return (long)(sw.Elapsed.TotalMilliseconds * 1000000);
		}

		public static long ColorInversion3(RGB[,] img, int n)
		{
			sw.Start();
			for (int j = 0; j < n; j++)
			{
				for (int i = 0; i < n; i++)
				{
					img[i, j].R = 255 - img[i, j].R;
					img[i, j].G = 255 - img[i, j].G;
					img[i, j].B = 255 - img[i, j].B;
				}
			}
			sw.Stop();
			return (long)(sw.Elapsed.TotalMilliseconds * 1000000);
		}

		public static long ColorInversion4(RGB[,] img, int n)
		{
			sw.Start();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					img[i, j].R = 255 - img[i, j].R;
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					img[i, j].G = 255 - img[i, j].G;
					img[i, j].B = 255 - img[i, j].B;
				}
			}
			sw.Stop();
			return (long)(sw.Elapsed.TotalMilliseconds * 1000000);
		}

		public static long ColorInversion5(RGB[,] img, int n)
		{
			sw.Start();
			for (int i = 0; i < n; i += 2)
			{
				for (int j = 0; j < n; j += 2)
				{
					img[i, j].R = 255 - img[i, j].R;
					img[i, j].G = 255 - img[i, j].G;
					img[i, j].B = 255 - img[i, j].B;

					img[i, j + 1].R = 255 - img[i, j + 1].R;
					img[i, j + 1].G = 255 - img[i, j + 1].G;
					img[i, j + 1].B = 255 - img[i, j + 1].B;

					img[i + 1, j].R = 255 - img[i + 1, j].R;
					img[i + 1, j].G = 255 - img[i + 1, j].G;
					img[i + 1, j].B = 255 - img[i + 1, j].B;

					img[i + 1, j + 1].R = 255 - img[i + 1, j + 1].R;
					img[i + 1, j + 1].G = 255 - img[i + 1, j + 1].G;
					img[i + 1, j + 1].B = 255 - img[i + 1, j + 1].B;
				}
			}
			sw.Stop();
			return (long)(sw.Elapsed.TotalMilliseconds* 1000000);
		}
		
		static void Main(string[] args)
        {
			int[] sizes = { 100, 200, 300, 400, 500, 600, 700, 800 };
			for (int s = 0; s < 8; s++)
			{
				int n = sizes[s];
				Console.WriteLine("size: " + n);
				RGB[,] img = new RGB[n, n];
				Random r = new System.Random();
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
                        img[i, j] = new RGB
                        {
                            R = r.Next() % 256,
                            G = r.Next() % 256,
                            B = r.Next() % 256
                        };
                    }
				}
				for (int v = 1; v <= 5; v++)
				{
					Console.WriteLine("version: " + v);
					int rep = 100;
					while (rep-->0)
					{
						sw.Reset();
                        var time = v switch
                        {
                            1 => ColorInversion1(img, n),
                            2 => ColorInversion2(img, n),
                            3 => ColorInversion3(img, n),
                            4 => ColorInversion4(img, n),
                            _ => ColorInversion5(img, n),
                        };
                        Console.WriteLine(time);
					}
				}
			}
		}
    }
}
