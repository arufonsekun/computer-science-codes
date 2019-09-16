import pygame
import sys

def main():
	pygame.init()

	screen = pygame.display.set_mode((640, 480))

	background = pygame.Surface((640, 480))
	background.fill((0, 0, 0))

	player = pygame.Surface((10, 10))
	player.fill((255, 255, 255))

	state = 0
	x = 0

	while True:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit(0)

			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_LEFT:
					state = 1

				if event.key == pygame.K_RIGHT:
					state = 2

			if event.type == pygame.KEYUP:
				state = 0

		if state == 1:
			x -= 1

		elif state == 2:
			x += 1

		if x < 0:
			x = 0

		elif x > 630:
			x = 630

		screen.blit(background, (0, 0))
		screen.blit(player, (x, 235))
		pygame.display.flip()


if __name__ == '__main__':
	main()
